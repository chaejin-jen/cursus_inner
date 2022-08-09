#!/bin/bash
#f=4_410_200_200;
f=199_410_200_200;
for i in range {1..199} ; do
	cat $f | grep " $i " | wc -l;
done
