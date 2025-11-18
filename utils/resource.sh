#!/bin/sh

source="$1"
output="$2"

#make output dir
mkdir -p "${output}"

#copy
cp -rv "${source}/spek.sh" "${output}/spek.sh"
cp -rv "${source}/TTKRoutine.sh" "${output}/TTKRoutine.sh"
cp -rv "${source}/TTKRoutineCopy.sh" "${output}/TTKRoutineCopy.sh"

#chmod
chmod +x "${output}/spek.sh"
chmod +x "${output}/TTKRoutine.sh"
chmod +x "${output}/TTKRoutineCopy.sh"
