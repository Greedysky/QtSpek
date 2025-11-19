#!/bin/sh

packname=QtSpek
packvern=0.8.5
rootpath=data/opt
datapath=data/DEBIAN

fullname=$1
if [ $# -eq 0 ]; then
  fullname=${packname}_${packvern}
fi

mkdir -p ${rootpath}
mkdir -p ${datapath}

# create control file
echo -n "Package: ${packname}
Version: ${packvern}
Section: sound
Priority: optional
Architecture: amd64
Installed-Size: $(du -s ${packname} | sed -e 's/[ \t].*//')
Maintainer: Matteo Bini <matteobin@tiepi.it>
Homepage: http://spek.cc/
Description: Acoustic spectrum analyser
 Spek helps to analyse your audio files by showing their spectrogram.
 It supports all popular lossy and lossless audio file formats.\n" > ${datapath}/control

# create postinst file
echo -n "#!/bin/bash
sh /opt/${packname}/install.sh\n" > ${datapath}/postinst
chmod +x ${datapath}/postinst

# create prerm file
echo -n "#!/bin/bash
sh /opt/${packname}/uninstall.sh\n" > ${datapath}/prerm
chmod +x ${datapath}/prerm

# create data path
mv ${packname} ${rootpath}

# create install package
dpkg -b data ${fullname}.deb
