title PUBLISH
color 1f
@echo off

cls

if not exist version.ver (
	(
		echo Prova de conceito
		echo 0
	)> version.ver 
)

echo Digite um comentario para a nova versao do projeto: & echo.

set /p texto=Comentario:

< version.ver (
	set /p projectName=
	set /p projectVersion=
)

if exist publish_log.txt (
	(
		echo Versao %projectVersion%:
		echo %texto% & echo.
	)>> publish_log.txt
) else (
	(
		echo Controle de versao da %projectName% & echo.
		echo Versao %projectVersion%:
		echo %texto% & echo.
	)> publish_log.txt 
)

set /a "projectNewVersion=%projectVersion% + 1"

(
	echo %projectName%
	echo %projectNewVersion%
)> version.ver

set "dirOutput=versao%projectVersion%"

robocopy "%cd%\..\Prova_Conceito" "%cd%/%dirOutput%" /E

cd "%dirOutput%"

(
	echo Controle de versao do %projectName% & echo.
	echo Versao %projectVersion%:
	echo %texto% & echo.
)> publish_log_versao%projectVersion%.txt 
