#include <getopt.h>
#include <iostream>

void Help() {
	std::cout <<
		"usage: maroon_mapper [options] <reference> <sequences>\n"
		"\n"
		"arguments:\n"
		"	<reference>		input reference genome in FASTA format\n"
		"	<sequences> 	input sequences file in FASTA/FASTQ format\n"
		"\n"
		"options:\n"
		"	-h, --help		prints this help message\n"
		"	--version		prints the version number\n";
}
