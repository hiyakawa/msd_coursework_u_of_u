#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/laurazhang/myLocalGithubRepo/Day18/xcode
  make -f /Users/laurazhang/myLocalGithubRepo/Day18/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/laurazhang/myLocalGithubRepo/Day18/xcode
  make -f /Users/laurazhang/myLocalGithubRepo/Day18/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/laurazhang/myLocalGithubRepo/Day18/xcode
  make -f /Users/laurazhang/myLocalGithubRepo/Day18/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/laurazhang/myLocalGithubRepo/Day18/xcode
  make -f /Users/laurazhang/myLocalGithubRepo/Day18/xcode/CMakeScripts/ReRunCMake.make
fi

