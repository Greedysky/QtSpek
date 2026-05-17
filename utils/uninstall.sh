#!/bin/sh

username=`logname`
if [ "${username}" = "root" ]; then
  homepath=/root
else
  homepath=/home/${username}
fi

rm -rf /opt/ttk/QtSpek
rm -f ${homepath}/.local/share/applications/QtSpek.desktop
rm -f ${homepath}/.local/share/metainfo/qtspek.metainfo.xml
