@ECHO off

REM
REM Automated Build Script for RacingBrains to automate the update process by grabbing the latest from the source
REM control repository, used here is subversion (svn) though it shouldn't be hard to modify to Git or Hg.
REM
REM This may be run by an automated process to clean and/or build each project with an /automated/auto_ script.
REM
REM <!-- Copyright (c) 2016 Tim Beaudet - All Rights Reserved -->
REM -------------------------------------------------------------------------------------------------------------------

REM This should go back to project_root to update, which by default was 2 levels back from: project_root/build/automated/
PUSHD ..\..\

(ECHO.)>>%abs_detailed_report_file%
(ECHO.)>>%abs_detailed_report_file%
(ECHO updating from source control of %CD%)>>%abs_detailed_report_file%
(ECHO --------------------------------------------------------)>>%abs_detailed_report_file%

svn update --quiet --non-interactive>>%abs_detailed_report_file%
POPD
