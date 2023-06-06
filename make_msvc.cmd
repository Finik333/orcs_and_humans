@echo off
pushd %~dp0

@rem Global settingh
set CMakeExecutable=cmake.exe

@rem Print required env variables:
echo BOOST_ROOT=%BOOST_ROOT%
echo OPENFST_ROOT=%OPENFST_ROOT%
echo MKL_ROOT=%MKL_ROOT%

@rem Work directories
set BuildDir=build
set InstallDir=targets

set MakeFlag=0
set InstallFlag=0
set InstallTarget=

@rem Parse args
:Loop
if "%1"=="" (
  goto Continue
) else if "%1"=="cleanup" (
  rmdir /q /s %BuildDir% > nul 2>&1
) else if "%1"=="make" (
  set MakeFlag=1
) else if "%1"=="install" (
  set InstallFlag=1
) else if "%1"=="loadenv" (
  call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvarsamd64_x86.bat";
) else (
  echo "Unknown arg '%1'"
)
shift
goto Loop
:Continue

if "%InstallFlag%"=="1" (
  rmdir /q /s %InstallDir% > nul 2>&1
  mkdir %InstallDir% > nul 2>&1
  set InstallTarget=--target INSTALL
)

mkdir %BuildDir% > nul 2>&1
cd %BuildDir%

@rem Configure
%CMakeExecutable% .. -G "Visual Studio 15 2017 Win64" -DCMAKE_INSTALL_PREFIX=..\%InstallDir% -DPARANOID_MODE=OFF
if errorlevel 1 pause

@rem Make
if "%MakeFlag%"=="1" (
  %CMakeExecutable% --build . --config Release %InstallTarget%
  if errorlevel 1 pause
)

cd ..
