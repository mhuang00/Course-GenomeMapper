# Coding a read-to-reference mapper for third-generation sequencing data

<p align="middle">
  <img src="logo/lbcb.png" width="400" />
</p>

New advances in genome sequencing technologies have vastly advanced the usability of obtained fragments due to the manifold increase of their length. The only drawback is the decreased accuracy, but the continuous improvements will eventually reach error levels that are negligible. Finding the origin and per nucleotide relationship of a sequenced read and a reference genome has various vital use cases in bioinformatics, and is usually based on heuristic short substring matching followed by exact alignment via dynamic programming. The combination of increased length and error rate led to development of new algorithms, one of which will be presented and implemented during this course.

The main goal of this course is for participants to individually code the whole project in several steps, get familiar with C++, basics of compilation methods, version control, unit tests and continuous integration. At the end of the course, each participant will have implemented several standalone libraries that enable placement and similarity description between a large amount of substrings of various sizes, and a much longer string from which they all originate. Combining those libraries into a single executable will enable mapping of long fragments obtained with latest sequencing technologies to a reference genome.
