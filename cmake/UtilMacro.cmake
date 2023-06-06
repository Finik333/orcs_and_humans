#  macro force_add_flags(flags_variable flag0 flag1 flag2 ...)
#        adds arguments not found in flags_variable to the end.
#        Does not remove duplicate arguments already existing in flags_variable, be careful!
#        It also separates arguments that are grouped as a string:
#          ["-O3 -g"] instead of [-O3 -g].
#
macro(force_add_flags FLAG_LIST)
  set(PARAMETER_LIST ${${FLAG_LIST}})
  separate_arguments(PARAMETER_LIST)
  set(NEW_PARAMETER ${${FLAG_LIST}})

  foreach(REQUIRED_ARG ${ARGN})
    set(TMP ${REQUIRED_ARG})
    separate_arguments(TMP)

    foreach(OPTION ${TMP})
      set(FOUND FALSE)
      foreach(P_ARG ${PARAMETER_LIST})
        if(${P_ARG} STREQUAL ${OPTION})
          set(FOUND TRUE)
        endif()
      endforeach()

      if(NOT FOUND)
        set(NEW_PARAMETER "${NEW_PARAMETER} ${OPTION}")
      endif()
    endforeach()

  endforeach()
  set(${FLAG_LIST} ${NEW_PARAMETER} CACHE STRING "" FORCE)
endmacro()
