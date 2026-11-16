#!/usr/bin/env bash
set -euo pipefail

project_root="$(cd "$(dirname "$0")/.." && pwd)"
build_dir="$project_root/build/qt-tests"
qmake_bin="${QMAKE:-qmake}"
if [[ -z "${QMAKE:-}" && -x /opt/homebrew/opt/qt@5/bin/qmake ]]; then
  qmake_bin=/opt/homebrew/opt/qt@5/bin/qmake
fi

mkdir -p "$build_dir"
cd "$build_dir"
"$qmake_bin" "$project_root/tests/InsToCartTests.pro"
make -s -j "${INSTOCART_BUILD_JOBS:-4}"
QT_QPA_PLATFORM="${QT_QPA_PLATFORM:-offscreen}" ./InsToCartTests "$@"
