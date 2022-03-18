#pragma once

#include <iostream>

template <size_t K>
    requires(K == 128)
class aes_key
{
private:
    uint8_t key[K/8];

public:
    consteval aes_key(const char (&s)[(K/8)+1]) noexcept
    {
        for (size_t i = 0; i < (K/8); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9')
                key[i] = c - '0';
            else if (c >= 'a' && c <= 'f')
                key[i] = (c - 'a') + 0xa;
            else if (c >= 'A' && c <= 'F')
                key[i] = (c - 'A') + 0xA;
            else
                key[i] = 0;
        }
    }

    consteval operator const uint8_t *() const noexcept
    {
        return key;
    }

    consteval auto size() const noexcept
    {
        return K;
    }
};

template <typename T, size_t N, size_t K>
    requires((std::same_as<std::remove_cvref_t<T>, char> || 
              std::same_as<std::remove_cvref_t<T>, unsigned char> ||
              std::same_as<std::remove_cvref_t<T>, uint8_t>) 
             && N > 0)
class compiletime_aes {
public:
    T data[N];

    consteval compiletime_aes(const T (&s)[N], const aes_key<K> &key) noexcept
    {
        std::copy(s, s + N, data);
        (void)key;
        data[0] += key[0];
    }

    consteval operator const T *() const noexcept
    {
        return data;
    }

    consteval auto size() const noexcept
    {
        return N;
    }

    void print(void) const noexcept
    {
        for (size_t i = 0; i < N; i++) {
            std::cout << (char)(data[i]);
        }
        std::cout << std::endl;

        std::cout << "Length: " << N << std::endl;
        std::cout << "Rounds: " << rounds() << std::endl;
    }
    
private:
    constexpr size_t rounds() const noexcept
    {
        return ((N + K - 1) / K);
    }
};
