cmake_minimum_required(VERSION 3.16)

project(PngPacker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

include_directories(".")
link_directories(".")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PngPacker
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
		resource.qrc
		
		projectlistwidget.h projectlistwidget.cpp
		defaultwidget.h defaultwidget.cpp
		packeddialog.h packeddialog.cpp
		unpackeddialog.h unpackeddialog.cpp
		param.h
		packedwidget.h packedwidget.cpp
		unpackedwidget.h unpackedwidget.cpp
		code.h
		qtimagereader.h qtimagereader.cpp
		qtimagewriter.h qtimagewriter.cpp
		packer/core/VImage.hpp packer/core/VImageReader.hpp packer/core/VImageWriter.hpp packer/core/VLayouter.hpp packer/core/VPacker.hpp packer/core/VProfileReader.hpp packer/core/VProfileWriter.hpp packer/core/VScanner.hpp packer/core/VUnpakcer.hpp packer/data/data.hpp packer/impl/DefaultProfileReader.hpp packer/impl/DefaultProfileWriter.hpp packer/impl/DefaultScanner.hpp packer/impl/Image.hpp packer/impl/ImageReader.hpp packer/impl/ImageWriter.hpp packer/impl/Packer.hpp packer/impl/ScaledLayouter.hpp packer/impl/Unpacker.hpp packer/raii/CharBuffer.hpp packer/raii/FilePtr.hpp packer/util/Bitmap.hpp packer/util/util.hpp packer/packer.hpp
		
		
		
		
		
		
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PngPacker APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PngPacker SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PngPacker
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(PngPacker PRIVATE Qt${QT_VERSION_MAJOR}::Widgets packer)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.PngPacker)
endif()
set_target_properties(PngPacker PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS PngPacker
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PngPacker)
endif()
