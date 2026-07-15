add_library(QcPerfQcomDsp STATIC
    src/qcom_dsp.c
    src/dspquery_stub.c
    
)

find_path(FASTRPC_INCLUDE_DIR AEEStdDef.h
    HINTS "${CMAKE_SOURCE_DIR}/backends/qcom-dsp/deps/include"
    NO_CMAKE_FIND_ROOT_PATH
)

find_library(FASTRPC_LIBRARY NAMES cdsprpc
    HINTS "${CMAKE_SOURCE_DIR}/backends/qcom-dsp/deps/lib"
    NO_CMAKE_FIND_ROOT_PATH
)

target_include_directories(QcPerfQcomDsp PUBLIC
    inc
    ${FASTRPC_INCLUDE_DIR}
)

target_link_libraries(QcPerfQcomDsp PUBLIC 
    ${FASTRPC_LIBRARY}
)
