@echo off
PUSHD %~dp0

set LCEXE="%1"
set OUTPUT="%2/po"
set SOURCE="%3/po"

::make output dir
if not exist %OUTPUT% md %OUTPUT%

::make
for /r %SOURCE% %%f in (*.ts) do %LCEXE% %%f

::rename
for /r %SOURCE% %%f in (*.qm) do ren %%f *.ln

::move
for /r %SOURCE% %%f in (*.ln) do move /y %%f %OUTPUT%

echo translate finished!
echo =============================================================================

POPD %~dp0
