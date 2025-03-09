#!/bin/zsh
set -e

$PWD/../client/bin/the_village_shop_client
$PWD/../server/bin/the_village_shop_server

echo "Test Successful!"