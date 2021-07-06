# Setup

Each participant should choose a color which will be the name of the projects namespace. The setup consist of creating a C++ program and naming it in form of `<color>_mapper`, while using CMake for the build. The program has to accept two mandatory files as floating arguments and enable options `-h` (`--help`) and `--version`, which are used for the help and version message (follow [SemVer](https://semver.org/)), respectively. Enable additional floating arguments if there are multiple sequence files and combine them after loading. Suggested argument parser is [optarg](https://linux.die.net/man/3/optarg), but this feature can be implemented independently.

The first file will contain a reference genome in [FASTA](https://en.wikipedia.org/wiki/FASTA_format) format, while the second file contains the set of fragments in either FASTA or [FASTQ](https://en.wikipedia.org/wiki/FASTQ_format) format. The files need to be parsed and stored in memory, and some basic statistics should be outputted to stderr for the reference and the set of all fragments, such as number of sequences, average length, N50 length, minimal and maximal length, etc.You can add [bioparser](https://github.com/rvaser/bioparser) to the project via CMake, either with [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) or as a git submodule (https://git-scm.com/book/en/v2/Git-Tools-Submodules), the former being preferable. Bioparser supports both needed formats and the files can also be compressed with gzip. You can implement parsing independently as well.

The first version of the mapper can be tested on an Oxford Nanopore Technologies data set obtained by sequencing the Escherichia coli K-12 substr. MG1655 genome. The data set is available from Loman Labs [here](http://lab.loman.net/2015/09/24/first-sqk-map-006-experiment/) (download both MAP-006-1 and MAP-006-2 FASTA files), while the reference genome is available from NCBI [here](https://ftp.ncbi.nlm.nih.gov/genomes/all/GCF/000/005/845/GCF_000005845.2_ASM584v2/GCF_000005845.2_ASM584v2_genomic.fna.gz).

Sample mapper runs after the setup step is completed, can be seen below:

**Input:**
```bash
<color>_mapper GCF_000005845.2_ASM584v2_genomic.fna MAP006-1_2D_pass.fasta
```
**Output:**
```bash
<basic statistics of reference>
<basic statistics of fragment file>
```

**Input:**
```bash
<color>_mapper GCF_000005845.2_ASM584v2_genomic.fna MAP006-1_2D_pass.fasta MAP006-2_2D_pass.fasta
```
**Output:**
```bash
<statistics of reference>
<statistics of both fragment files together>
```

**Input:**
```bash
<color>_mapper -h
```
**Output:**
```bash
<message describing how to run the tool with supported arguments>
```

**Input:**
```bash
<color>_mapper --version
```
**Output:**
```bash
v0.1.0
```
