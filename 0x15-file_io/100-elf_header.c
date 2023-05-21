#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * validate_elf - Checks if a file is an ELF file.
 * @e_ident: Pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, it exits with code 98.
 */
void validate_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
		    e_ident[i] != 'E' &&
		    e_ident[i] != 'L' &&
		    e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Invalid ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_header_info - Prints the magic numbers of an ELF header.
 * @e_ident: Pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_header_info(unsigned char *e_ident)
{
	int i;

	printf(" Header Info: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_section_info - Prints the section info of an ELF header.
 * @e_ident: Pointer to an array containing the ELF magic numbers.
 */
void print_section_info(unsigned char *e_ident)
{
	printf(" Section Info: %s\n", (e_ident[EI_DATA] == ELFDATA2LSB) ? "Little Endian" : "Big Endian");
}

/**
 * print_elf_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: Pointer to an array containing the ELF magic numbers.
 */
void print_elf_type(unsigned int e_type, unsigned char *e_ident)
{
	printf(" ELF Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry_point - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: Pointer to an array containing the ELF magic numbers.
 */
void print_entry_point(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry Point Address: ");

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_file - Closes an ELF file.
 * @file_descriptor: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed, it exits with code 98.
 */
void close_file(int file_descriptor)
{
	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to close file descriptor %d\n", file_descriptor);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF file or
 * the function fails, it exits with code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int file_descriptor, read_result;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
		exit(98);
	}

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot open file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_file(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
		exit(98);
	}

	read_result = read(file_descriptor, header, sizeof(Elf64_Ehdr));
	if (read_result == -1)
	{
		free(header);
		close_file(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Failed to read file %s\n", argv[1]);
		exit(98);
	}

	validate_elf(header->e_ident);
	printf("ELF Header:\n");
	print_header_info(header->e_ident);
	print_section_info(header->e_ident);
	print_elf_type(header->e_type, header->e_ident);
	print_entry_point(header->e_entry, header->e_ident);

	free(header);
	close_file(file_descriptor);

	return (0);
}
