add_library(QcPerfQcomDsp STATIC
    src/qcom_dsp.c
    src/dspquery_stub.c
    
)

if(NOT FASTRPC_SDK_DIR)
    message(FATAL_ERROR
        "FASTRPC_SDK_DIR is not set. "
        "Point it to the extracted fastrpc SDK root (the directory containing usr/include/fastrpc and usr/lib). "
        "Example: -DFASTRPC_SDK_DIR=/path/to/fastrpc_extract")
endif()

find_path(FASTRPC_INCLUDE_DIR AEEStdDef.h
    HINTS "${FASTRPC_SDK_DIR}/usr/include/fastrpc"
    NO_CMAKE_FIND_ROOT_PATH
)

find_library(FASTRPC_LIBRARY NAMES cdsprpc
    HINTS "${FASTRPC_SDK_DIR}/usr/lib/aarch64-linux-gnu"
    NO_CMAKE_FIND_ROOT_PATH
)

target_include_directories(QcPerfQcomDsp PUBLIC
    inc
    ${FASTRPC_INCLUDE_DIR}
)

target_link_libraries(QcPerfQcomDsp PUBLIC 
    ${FASTRPC_LIBRARY}
)
