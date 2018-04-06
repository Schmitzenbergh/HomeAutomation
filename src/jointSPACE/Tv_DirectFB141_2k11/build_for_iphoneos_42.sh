#!/bin/bash

################################################################################
#
# Copyright (c) 2008-2009 Christopher J. Stawarz
#
# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation files
# (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge,
# publish, distribute, sublicense, and/or sell copies of the Software,
# and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
# BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
# ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
################################################################################

# originally from http://pseudogreen.org/blog/build%5Fautoconfed%5Flibs%5Ffor%5Fiphone.html
# added symbolic link in my dev like described in http://vonluck.wordpress.com/2009/09/16/mac-osx-10-6-iphone-os-3-1-simulator-linking-errors/
# for clinkc I manually adapted the makefile and replaced 386 by 686 (based on curl config file)
# curl built without-zlib

# Disallow undefined variables
set -u


default_gcc_version=4.2
default_iphoneos_version=4.2
default_macos_version=10.6

GCC_VERSION="${GCC_VERSION:-$default_gcc_version}"
export IPHONEOS_DEPLOYMENT_TARGET="${IPHONEOS_DEPLOYMENT_TARGET:-$default_iphoneos_version}"
export MACOSX_DEPLOYMENT_TARGET="${MACOSX_DEPLOYMENT_TARGET:-$default_macos_version}"


usage ()
{
    cat >&2 << EOF
Usage: ${0##*/} [-ht] [-p prefix] target [configure_args]
	-h	Print help message
	-p	Installation prefix (default: \$HOME/Developer/Platforms/...)
	-t	Use 16-bit Thumb instruction set (instead of 32-bit ARM)

The target must be "devicev6", "devicev7" or "simulator".  Any additional arguments
are passed to configure.

The following environment variables affect the build process:

	GCC_VERSION			(default: $default_gcc_version)
	IPHONEOS_DEPLOYMENT_TARGET	(default: $default_iphoneos_version)
	MACOSX_DEPLOYMENT_TARGET	(default: $default_macos_version)

EOF
}


while getopts ":hp:t" opt; do
    case $opt in
	h  ) usage ; exit 0 ;;
	p  ) prefix="$OPTARG" ;;
	t  ) thumb_opt=thumb ;;
	\? ) usage ; exit 2 ;;
    esac
done
shift $(( $OPTIND - 1 ))

if (( $# < 1 )); then
    usage
    exit 2
fi

target=$1
shift

case $target in

    devicev7 )
	arch=armv7
	platform=iPhoneOS
	extra_cflags="-m${thumb_opt:-no-thumb} -mthumb-interwork"
	;;

    devicev6 )
	arch=armv6
	platform=iPhoneOS
	extra_cflags="-m${thumb_opt:-no-thumb} -mthumb-interwork"
	;;

    simulator )
	arch=i386
	platform=iPhoneSimulator
	extra_cflags="-D__IPHONE_OS_VERSION_MIN_REQUIRED=${IPHONEOS_DEPLOYMENT_TARGET%%.*}0000"
	;;

    * )
	usage
	exit 2

esac


platform_dir="/Developer/Platforms/${platform}.platform/Developer"
platform_bin_dir="${platform_dir}/usr/bin"
platform_sdk_dir="${platform_dir}/SDKs/${platform}${IPHONEOS_DEPLOYMENT_TARGET}.sdk"
prefix="${prefix:-${platform_dir}/usr}"

#added some stuff so the libraries can also use already built libraries
export LD="${platform_bin_dir}/ld"
export CC="${platform_bin_dir}/gcc"
export CFLAGS="-arch ${arch} -pipe -Os -gdwarf-2 -isysroot ${platform_sdk_dir} ${extra_cflags} -I${prefix}/include"
# added -L${prefix}/lib to include built libraries
export LDFLAGS="-arch ${arch} -L${prefix}/lib"
export CXX="${platform_bin_dir}/g++"
export CXXFLAGS="${CFLAGS}"
export CPP="${platform_bin_dir}/cpp"
export CXXCPP="${CPP}"
# added to include pc files of built libraries
export PKG_CONFIG_PATH="${prefix}/lib/pkgconfig"
# added to include headers of built libraries

# you can bundle the libraries with lipo -create remco-armv7/remco-iphoneos/jslibrc_supply.o remco/remco-iphoneos/jslibrc_supply.o -output jslibrc_supply.o
make -f makefile.voodoo.iphone
make -f makefile.voodoo.iphone package
