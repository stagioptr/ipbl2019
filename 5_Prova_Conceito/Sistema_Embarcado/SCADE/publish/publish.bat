title PUBLISH
color 1f
@echo off

cls

if not exist version.ver (
	(
		echo SCADE
		echo 0
	)> version.ver 
)

< version.ver (
	set /p libName=
	set /p libVersion=
)

echo Digite um comentario para a versao %libVersion% da biblioteca %libName%: & echo.

set /p texto=Comentario:

if exist publish_log.txt (
	(
		echo Versao %libVersion%:
		echo %texto% & echo.
	)>> publish_log.txt
) else (
	(
		echo Controle de versao do lib %libName% & echo.
		echo Versao %libVersion%:
		echo %texto% & echo.
	)> publish_log.txt 
)

set /a "libNewVersion=%libVersion% + 1"

(
	echo %libName%
	echo %libNewVersion%
)> version.ver

set "dirOutput=versao%libVersion%"

robocopy "%cd%\..\KCG" "%cd%/%dirOutput%" *.c *.h /E

cd "%dirOutput%"

(
	echo Controle de versao do lib %libName% & echo.
	echo Versao %libVersion%:
	echo %texto% & echo.
)> publish_log_versao%libVersion%.txt 
