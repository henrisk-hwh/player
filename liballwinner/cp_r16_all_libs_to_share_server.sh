#!/bin/sh
cp -rf /home/lilihong/workspace/tina2.0/out/astar-parrot/compile_dir/target/liballwinner/LIBRARY/install/lib /home/lilihong/share_server
cp -rf /home/lilihong/workspace/tina2.0/out/astar-parrot/compile_dir/target/liballwinner/tinaplayer/libtinaplayer.so /home/lilihong/share_server/lib
cd /home/lilihong/share_server/lib && rm libz.so libxml2.so libcrypto.so libssl.so
echo "cp all libs to share_server successfully"
