cmake_minimum_required(VERSION 3.27)
project(OOP_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(.)
include_directories(Classes)

add_executable(OOP_project
        Classes/AddressLineEdit.cpp
        Classes/BuyableScrollAreaMain.cpp
        Classes/Cart.cpp
        Classes/Clothing.cpp
        Classes/Customer.cpp
        Classes/Order.cpp
        Classes/Price.cpp
        Classes/Product.cpp
        Classes/Service.cpp
        Classes/StoreSystem.cpp
        Classes/Wallet.cpp
        Classes/BuyableScrollAreaMain.h
        Classes/Cart.h
        Classes/Clothing.h
        Classes/Customer.h
        Classes/Order.h
        Classes/Price.h
        Classes/Product.h
        Classes/Service.h
        Classes/StoreSystem.h
        Classes/Wallet.h
        Templates/Listing.h
        Templates/LoaderSaver.h
        Enums/BuyableDisplayedType.h
        Enums/BuyableSortedBy.h
        Enums/Color.h
        Enums/ServiceType.h
        Interfaces/Buyable.cpp
        Interfaces/Buyable.h
        Interfaces/BuyableScrollArea.cpp
        Interfaces/BuyableScrollArea.h
        Interfaces/DynamicWidget.h
        Interfaces/MoneyPossesive.cpp
        Interfaces/MoneyPossesive.h
        Interfaces/Serializable.h
        ExternalLibs/nlohmann/json.hpp
        main.cpp
        mainwindow.cpp
        mainwindow.h
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()


target_link_libraries(OOP_project
        Qt::Core
        Qt::Gui
        Qt::Widgets
)