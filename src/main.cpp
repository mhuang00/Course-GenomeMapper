#include <getopt.h>
#include <iostream>
#include <fstream>
	
#include <stdio.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>

#include "bioparser/fasta_parser.hpp"
#include "bioparser/fastq_parser.hpp"

struct Sequence {
	public:
		std::string id;
		std::string sequence;
		
		Sequence(  // required arguments
    					const char* id, std::uint32_t id_len,
    					const char* sequence, std::uint32_t sequence_len) :
    						id(id, id_len),
    						sequence(sequence, sequence_len) {
    						}
};


void Help() {
        std::cout <<
                "usage: maroon_mapper [options] <reference> <sequences>\n"
                "\n"
                "arguments:\n"
                "       <reference>             input reference genome in FASTA format\n"
                "       <sequences>     input sequences file in FASTA/FASTQ format\n"
                "\n"
                "options:\n"
                "       -h, --help              prints this help message\n"
                "       --version               prints the version number\n";
}

void Parser(
		std::string& reference_path,
		std::string& fragments_path,
		std::vector<std::unique_ptr<Sequence>>* reference,
		std::vector<std::unique_ptr<Sequence>>* fragments) {

		//std::vector<std::unique_ptr<Sequence>> reference;
		//std::vector<std::unique_ptr<Sequence>> fragments;
		
		auto r = bioparser::Parser<Sequence>::Create<bioparser::FastaParser>(reference_path);
		*reference = r->Parse(-1);

		auto f = bioparser::Parser<Sequence>::Create<bioparser::FastaParser>(fragments_path);
		*fragments = f->Parse(-1);

}

void Map(std::vector<std::unique_ptr<Sequence>>& query) {
		int quantity = query.size();
		std::vector<int> lengths;
		int total_length = 0;

		for (auto& it : query) {
			lengths.push_back(it->sequence.size());
			total_length += (it->sequence.size());
		}
			
		int avg = total_length / quantity;
		sort(lengths.begin(), lengths.end(), std::greater<int>());
		int min = lengths[quantity-1];
		int max = lengths[0];

		int length_accumulation = 0;
		while (length_accumulation < (total_length / 2)) {
			for (int i = 0; i < quantity; i++) {
				length_accumulation += lengths[i];
			}
		}
		int n50 = length_accumulation;	

		//print statistics
		std::cout << "Number of sequences: " << quantity << std::endl;
		std::cout << "Average length: " << avg << std::endl;
		std::cout << "Minimum length: " << min << std::endl;
		std::cout << "Maximum length: " << max << std::endl;
		std::cout << "N50: " << n50 << std::endl << std::endl;
}


int main(int argc, char** argv) {
        
        int arg;
        while ((arg = getopt(argc, argv, ":hv")) != -1) {
                switch (arg) {
                        case 'h': Help(); return 0;
                        case 'v': std::cout << VERSION << std::endl; return 0;
                }
        }

        std:: vector<std:: string> arguments;
        for (int i = optind; i < argc; ++i) {
            arguments.push_back(argv[i]); //load argv into vector arguments
        }

        if (argc < 3) {
                std::cerr << "Error: Missing arguments!\n" << std::endl;
                Help();
                return 1;
        }        

		std::vector<std::unique_ptr<Sequence>> reference;
		std::vector<std::unique_ptr<Sequence>> fragments;

        Parser(arguments[0], arguments[1], &reference, &fragments);
        std::cout << std::endl << "Statistics: Reference ..." << std::endl;
        Map(reference);
        std::cout << "Statistics: Fragments ..." << std::endl;
        Map(fragments);
        return 0;
}

