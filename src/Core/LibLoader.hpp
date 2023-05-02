/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** LibLoader
*/

#pragma once

#include <iostream>
#include <dlfcn.h>

class LibLoader {
    public:
        /**
         * @brief Construct a new Lib Loader object
        */
        LibLoader() : _handle(nullptr) {}
        
        /**
         * @brief Destroy the Lib Loader object
        */
        ~LibLoader() {
            Close();
        }

        /**
         * @brief Open a dynamic library
         * 
         * @param libName The name of the library to open
        */
        bool Open(const std::string& libName) {
            Close();
            _handle = dlopen(libName.c_str(), RTLD_LAZY);
            if (!_handle) {
                _error = dlerror();
                std::cerr << "Error : can't open dynamic library." << std::endl;
                std::cerr << _error << std::endl;
                return false;
            }
            _libName = libName;
            return true;
        }

        /**
         * @brief Close the dynamic library
        */
        void Close() {
            if (_handle) {
                dlclose(_handle);
                _handle = nullptr;
                _error.clear();
                _libName.clear();
            }
        }

        /**
         * @brief Get a symbol from the dynamic library
         * @brief Call the method like that : GetSymbol<type>("symbol_name")
         * 
         * @tparam T The type of the symbol
         * @param symbol_name The name of the symbol
         * 
         * @return T The symbol
         * @return nullptr If the symbol is not found
         * @return nullptr If the library is not open
        */
        // template<typename T>
        void *GetSymbol(const std::string& symbol_name) {
            if (!_handle) {
                _error = "Library is not open";
                std::cerr << "Error : " << _error << std::endl;
                return nullptr;
            }

            void *symbol = dlsym(_handle, symbol_name.c_str());
            if (!symbol) {
                _error = dlerror();
                std::cerr << "Error : can't find symbol." << std::endl;
                std::cerr << _error << std::endl;
                return nullptr;
            }
            return symbol;
        }

        /**
         * @brief Get the last error
        */
        std::string GetLastError() const {
            return _error;
        }

        /**
         * @brief Get the name of the library
        */
        std::string GetLibName() const {
            return _libName;
        }

    private:
        void* _handle;
        std::string _error;
        std::string _libName;
};