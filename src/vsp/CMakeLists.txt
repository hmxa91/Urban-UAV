CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# include the CTest framework
include(CTest)

IF("${CMAKE_SYSTEM}" MATCHES "Linux")
	SET( LINUX_LIBS
		pthread
		)
ELSE()
	SET ( LINUX_LIBS )
ENDIF()

INCLUDE_DIRECTORIES( ${VSP_SOURCE_DIR}
	${UTIL_INCLUDE_DIR}
	${GEOM_CORE_INCLUDE_DIR}
	${GEOM_API_INCLUDE_DIR}
	${GUI_AND_DRAW_INCLUDE_DIR}
	${TRIANGLE_INCLUDE_DIR}
	${NANOFLANN_INCLUDE_DIR}
	${CLIPPER_INCLUDE_DIR}
	${CPPTEST_INCLUDE_DIRS}
	${LOAD_JPG_INCLUDE_DIR}
	${SCREENS_INCLUDE_DIR}
	${XMLVSP_INCLUDE_DIR}
	${CPPTEST_INCLUDE_DIR}
	${FLTK_INCLUDE_DIR}
	${LIBXML2_INCLUDE_DIR}
	${EIGEN3_INCLUDE_DIR}
	${CodeEli_INCLUDE_DIRS}
	${STEPCODE_INCLUDE_DIR}
	${LIBIGES_INCLUDE_DIR}
 )

IF( NOT VSP_NO_GRAPHICS )

	ADD_EXECUTABLE(vsp
	common.cpp
	main.cpp
	common.h
	main.h
	)

	set_target_properties( vsp PROPERTIES COMPILE_FLAGS "-DVSP_USE_FLTK=1")

	TARGET_LINK_LIBRARIES(vsp
		gui_interface_g
		gui_and_draw
		geom_core
		geom_api_g
		cfd_mesh
		triangle
		screens
		xmlvsp
		sixseries
		util
		tritri
		clipper
        Angelscript
        cartesian
        wavedragEL
		${CPPTEST_LIBRARIES}
		${LIBXML2_LIBRARIES}
		${FLTK_LIBRARIES}
		${OPENGL_LIBRARIES}
		${WINSOCK_LIBRARIES}
		${CMINPACK_LIBRARIES}
        ${STEPCODE_LIBRARIES}
		${LINUX_LIBS}
		${LIBIGES_LIBRARIES}
	)

	INSTALL( TARGETS vsp RUNTIME DESTINATION . )

	ADD_EXECUTABLE(apitest_g
	apitest_main.cpp
	../vsp/main.h.in
	)

	set_target_properties( apitest_g PROPERTIES COMPILE_FLAGS "-DVSP_USE_FLTK=1")

	TARGET_LINK_LIBRARIES(apitest_g
		geom_api_g
		gui_interface_g
		gui_and_draw
		geom_core
		cfd_mesh
		triangle
		util
		tritri
		clipper
        Angelscript
		screens
		xmlvsp
		sixseries
		cartesian
		wavedragEL
		${CPPTEST_LIBRARIES}
		${LIBXML2_LIBRARIES}
		${FLTK_LIBRARIES}
		${OPENGL_LIBRARIES}
		${WINSOCK_LIBRARIES}
		${CMINPACK_LIBRARIES}
		${STEPCODE_LIBRARIES}
		${LIBIGES_LIBRARIES}
	)

#	INSTALL( TARGETS apitest_g RUNTIME DESTINATION . )

ENDIF()

ADD_EXECUTABLE(apitest
apitest_main.cpp
../vsp/main.h.in
)

TARGET_LINK_LIBRARIES(apitest
	geom_api
	geom_core
	cfd_mesh
	triangle
	xmlvsp
	sixseries
	util
	tritri
	clipper
    Angelscript
    wavedragEL
	${CPPTEST_LIBRARIES}
	${LIBXML2_LIBRARIES}
	${WINSOCK_LIBRARIES}
	${CMINPACK_LIBRARIES}
	${STEPCODE_LIBRARIES}
	${LIBIGES_LIBRARIES}
)

ADD_EXECUTABLE(vspscript
common.cpp
scriptonly_main.cpp
common.h
../vsp/main.h.in
)

TARGET_LINK_LIBRARIES(vspscript
	geom_core
	geom_api
	cfd_mesh
	triangle
	xmlvsp
	sixseries
	util
	tritri
	clipper
	Angelscript
	wavedragEL
	${CPPTEST_LIBRARIES}
	${LIBXML2_LIBRARIES}
	${WINSOCK_LIBRARIES}
	${CMINPACK_LIBRARIES}
	${STEPCODE_LIBRARIES}
	${LIBIGES_LIBRARIES}
)

INSTALL( TARGETS vspscript RUNTIME DESTINATION . )
