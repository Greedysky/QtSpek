#!/bin/sh

source="$1"
output="$2"

#make output dir
mkdir -p "${output}"

#copy
cp -rv "${source}/QtSpek.sh" "${output}/QtSpek.sh"
cp -rv "${source}/TTKRoutine.sh" "${output}/TTKRoutine.sh"
cp -rv "${source}/TTKRoutineCopy.sh" "${output}/TTKRoutineCopy.sh"

#chmod
chmod +x "${output}/QtSpek.sh"
chmod +x "${output}/TTKRoutine.sh"
chmod +x "${output}/TTKRoutineCopy.sh"
