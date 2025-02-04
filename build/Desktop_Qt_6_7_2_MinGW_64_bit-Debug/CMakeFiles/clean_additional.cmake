# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "ASU_PRO_Report_Wizard_autogen"
  "CMakeFiles\\ASU_PRO_Report_Wizard_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ASU_PRO_Report_Wizard_autogen.dir\\ParseCache.txt"
  )
endif()
