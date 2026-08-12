if(QCPERF_OS_WINDOWS)
    set(DSPQUERY_STUB_SRC src/dspquery_stub_wos.c)
else()
    set(DSPQUERY_STUB_SRC src/dspquery_stub.c)
endif()

add_library(QcPerfQcomDsp STATIC
    src/qcom_dsp.c
    ${DSPQUERY_STUB_SRC}
    $<$<BOOL:${QCPERF_OS_WINDOWS}>:src/fastrpc_runtime.c>
)

set(FASTRPC_DIR "${CMAKE_SOURCE_DIR}/third-party/fastrpc")

if(NOT QCPERF_OS_WINDOWS)
    find_path(FASTRPC_INCLUDE_DIR AEEStdDef.h
        HINTS "${FASTRPC_DIR}/inc"
        NO_CMAKE_FIND_ROOT_PATH
    )

    find_library(FASTRPC_LIBRARY NAMES cdsprpc
        HINTS "${FASTRPC_DIR}/src/.libs"
        NO_CMAKE_FIND_ROOT_PATH
    )

    target_include_directories(QcPerfQcomDsp PUBLIC
        inc
        ${FASTRPC_INCLUDE_DIR}
    )

    target_link_libraries(QcPerfQcomDsp PUBLIC
        ${FASTRPC_LIBRARY}
    )
else()
    target_include_directories(QcPerfQcomDsp PUBLIC
        inc
    )

    target_link_libraries(QcPerfQcomDsp PUBLIC
        advapi32
    )
endif()
