title PUBLISH
color 1f
@echo off

cls

if not exist version.ver (
	
	echo Digite um nome para o sensor:

	set /p sensor=Nome:
)

if not exist version.ver (
	(
		echo %sensor%
		echo 0
	)> version.ver 
)

< version.ver (
	set /p driverName=
	set /p driverVersion=
)

echo Digite um comentario para a versao %driverVersion% do driver %driverName%: & echo.

set /p texto=Comentario:

if exist publish_log.txt (
	(
		echo Versao %driverVersion%:
		echo %texto% & echo.
	)>> publish_log.txt
) else (
	(
		echo Controle de versao do driver %driverName% & echo.
		echo Versao %driverVersion%:
		echo %texto% & echo.
	)> publish_log.txt 
)

set /a "driverNewVersion=%driverVersion% + 1"

(
	echo %driverName%
	echo %driverNewVersion%
)> version.ver

set "dirOutput=versao%driverVersion%"

robocopy "%cd%\..\driver_code" "%cd%/%dirOutput%" /E

cd "%dirOutput%"

(
	echo Controle de versao do driver %driverName% & echo.
	echo Versao %driverVersion%:
	echo %texto% & echo.
)> publish_log_versao%driverVersion%.txt 
