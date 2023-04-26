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
        LibLoader() : _handle(nullptr) {}
        
        ~LibLoader() {
            Close();
        }

        bool Open(const std::string& libName) {
            Close();
            _handle = dlopen(libName.c_str(), RTLD_LAZY);
            if (!_handle) {
                _error = dlerror();
                std::cerr << "Erreur : impossible de charger la librairie dynamique." << std::endl;
                std::cerr << _error << std::endl;
                return false;
            }
            _libName = libName;
            return true;
        }

        void Close() {
            if (_handle) {
                dlclose(_handle);
                _handle = nullptr;
                _error.clear();
                _libName.clear();
            }
        }

        template<typename T>
        T GetSymbol(const std::string& symbol_name) {
            if (!_handle) {
                _error = "La librairie n'est pas ouverte.";
                std::cerr << "Erreur : " << _error << std::endl;
                return nullptr;
            }

            void* symbol = dlsym(_handle, symbol_name.c_str());
            if (!symbol) {
                _error = dlerror();
                std::cerr << "Erreur : impossible de trouver le symbole." << std::endl;
                std::cerr << _error << std::endl;
                return nullptr;
            }
            return reinterpret_cast<T>(symbol);
        }

        std::string GetLastError() const {
            return _error;
        }

        std::string GetLibName() const {
            return _libName;
        }

    private:
        void* _handle;
        std::string _error;
        std::string _libName;
};