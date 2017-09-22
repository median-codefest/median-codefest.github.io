SET(OCULUS_ROOT_DIR "C:/Code/ExternalProjects/OculusSDK")
#SET(OCULUS_ROOT_DIR "$ENV{THIRD_PARTY_DIR}/OculusSDK")

find_path(OCULUS_INCLUDE_DIR
          OVR_CAPI.h
          PATHS /usr/local/include ${OCULUS_ROOT_DIR}/LibOVR/include)

find_library(OCULUS_LIBRARY
             PATHS /usr/local/lib ${OCULUS_ROOT_DIR}/LibOVR/lib
             NAMES LibOVR)
			 
 find_library(OCULUS_KERNEL_LIBRARY
			 PATHS /usr/local/lib ${OCULUS_ROOT_DIR}/LibOVRKernel/lib
            NAMES LibOVRKernel)
			 
find_path(OCULUS_KERNEL_INCLUDE_DIR
			GL/CAPI_GLE.h
			${OCULUS_ROOT_DIR}/LibOVRKernel/Src
			)
			 
# find_path(OCULUS_INCLUDE_DIR
          # OVR_CAPI.h
          # PATHS /usr/local/include ${OCULUS_ROOT_DIR}/LibOVR/include)

# find_library(OCULUS_LIBRARY
             # PATHS /usr/local/lib ${OCULUS_ROOT_DIR}/LibOVR/lib
             # NAMES LibOVR)
			 
# find_library(OCULUS_KERNEL_LIBRARY
			  # PATHS /usr/local/lib ${OCULUS_ROOT_DIR}/LibOVRKernel/lib
              # NAMES LibOVRKernel)
			 
# find_path(OCULUS_KERNEL_INCLUDE_DIR
			 # GL/CAPI_GLE.h
			 # ${OCULUS_ROOT_DIR}/LibOVRKernel/Src
			 # )
			
if(OCULUS_LIBRARY AND OCULUS_INCLUDE_DIR)
	set(OCULUS_FOUND TRUE)
	set(OCULUS_INCLUDE_DIRS ${OCULUS_INCLUDE_DIR} ${OCULUS_KERNEL_INCLUDE_DIR} CACHE STRING "The include paths needed to use oculus")
    set(OCULUS_LIBRARIES ${OCULUS_LIBRARY} ${OCULUS_KERNEL_LIBRARY} CACHE STRING "The libraries needed to use oculus")
endif()

#mark_as_advanced(OCULUS_INCLUDE_DIRS OCULUS_LIBRARIES)