#!/bin/bash -e

FILE="$1"
shift

LIBRARY="$1"
shift

JSLIBRARY="$1"
shift


echo "Building '$FILE' with '$LIBRARY'..."


DIR="${FILE/.tar.gz/}"


if test "$DIR" == "$FILE"; then
    echo "Package extension unsupported!"
    exit 1
fi


echo rm -rf "$DIR"

mkdir -p "$DIR"
mkdir -p "$DIR/lib"
mkdir -p "$DIR/include"
mkdir -p "$DIR/include/direct"
mkdir -p "$DIR/include/fusion"
mkdir -p "$DIR/include/voodoo"
mkdir -p "$DIR/include/gfx"

cp -a "$LIBRARY" "$DIR/lib/"
cp -a "$JSLIBRARY" "$DIR/lib/"
cp -r "Jslib/jslibapi/type" "$DIR/include"

while test -n "$1"; do
    HEADER="$1"
    shift

    case $HEADER in
        ConfigGeneric*)
            TARGET=`echo $HEADER | cut -d/ -f2-`
            echo "C $TARGET"
            ;;

        Source/*/include*)
            TARGET=`echo $HEADER | cut -d/ -f4-`
            echo "D $TARGET"
            ;;

        Source/DirectFB/lib*)
            TARGET=`echo $HEADER | cut -d/ -f4-`
            echo "L $TARGET"
            ;;

        Source/DirectFB/src*)
            TARGET=`echo $HEADER | cut -d/ -f4-`
            echo "I $TARGET"
            ;;

        Jslib/jslibrc/*)
            TARGET=`echo $HEADER | cut -d/ -f3-`
            echo "J $TARGET"
            ;;
			
        Jslib/jslibapi/*)
            TARGET=`echo $HEADER | cut -d/ -f3-`
            echo "J $TARGET"
            ;;
			
        *)
            echo "X $HEADER X"
            exit 2
            ;;
    esac

    cp -a "$HEADER" "$DIR/include/$TARGET"
done


tar czf "$FILE" "$DIR"

