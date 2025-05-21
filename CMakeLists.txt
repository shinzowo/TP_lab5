cmake_minimum_required(VERSION 3.5)

project(SweetBox_GUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        adddialog.h
        adddialog.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SweetBox_GUI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        adddialog.h
        adddialog.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SweetBox_GUI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SweetBox_GUI SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SweetBox_GUI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Подключаем заголовки
target_include_directories(SweetBox_GUI PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/SweetLibrary/include
)

# Подключаем импортную библиотеку
target_link_directories(SweetBox_GUI PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/SweetLibrary/lib
)

target_link_libraries(SweetBox_GUI
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    SweetLibrary
)

add_definitions(-DSWEETLIBRARY_EXPORTS)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SweetBox_GUI)
endif()
set_target_properties(SweetBox_GUI PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SweetBox_GUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SweetBox_GUI)
endif()

enable_testing()

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/SweetLibrary/lib)

add_executable(tst_adddialog
    tst_adddialog.cpp
    adddialog.cpp
    adddialog.h
)

target_link_libraries(tst_adddialog
    PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Widgets SweetLibrary
)

add_test(NAME tst_adddialog COMMAND tst_adddialog)



