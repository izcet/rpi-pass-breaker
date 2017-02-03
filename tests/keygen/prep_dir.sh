#!/bin/bash

DIR="seed_known"

MIN=1
MAX=20
S_min=0
S_max=16

while [ $MIN -le $MAX ] ; do
	smin=$S_min
	smax=$S_max
	if [ $MIN -lt 10 ] ; then
		drr="$DIR/known-0${MIN}"
	else
		drr="$DIR/known-${MIN}"
	fi
	mkdir "$drr"
	while [ $smin -le $smax ] ; do
		if [ $smin -lt 10 ] ; then
			mkdir "$drr/keylen-0${smin}"
		else
			mkdir "$drr/keylen-${smin}"
		fi

		smin=$(( $smin + 1 ))
	done
	MIN=$(( $MIN + 1 ))
done
