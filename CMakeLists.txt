# cmake_minimum_required(VERSION <specify CMake version here>)
project(OOP_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Classes)

add_executable(OOP_project
        Classes/Core/Currency.cpp
        Headers/Core/Currency.h
        Classes/Core/Product.cpp
        Headers/Core/Product.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        Headers/Domain/Wallet.h
        Classes/Domain/Wallet.cpp
        Headers/Domain/Clothing.h
        Enums/Color.h
        Classes/Domain/Clothing.cpp
        Headers/Domain/Cart.h
        Headers/Core/Price.h
        Headers/Interfaces/MoneyPossesive.h
        Classes/Interfaces/MoneyPossesive.cpp
        Classes/Core/Price.cpp
        Classes/Domain/Cart.cpp
        Headers/Domain/Customer.h
        Headers/Domain/Order.h
        Classes/Domain/Order.cpp
        Classes/Domain/Customer.cpp
        Headers/System/StoreSystem.h
        Classes/System/StoreSystem.cpp
        Templates/Listing.h
        Headers/Interfaces/Buyable.h
        Classes/Interfaces/Buyable.cpp
        Headers/Core/Service.h
        Enums/ServiceType.h
        Classes/Core/Service.cpp)
