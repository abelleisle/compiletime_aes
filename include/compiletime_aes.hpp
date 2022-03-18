template <typename T, size_t N>
    requires((std::same_as<std::remove_cvref_t<T>, char> || 
              std::same_as<std::remove_cvref_t<T>, unsigned char> ||
              std::same_as<std::remove_cvref_t<T>, uint8_t>) 
             && N > 0)
class compiletime_aes {
public:
    T data[N];

    consteval compiletime_aes(const T (&s)[N]) noexcept
    {
        std::copy(s, s + N, data);
        for (size_t i = 0; i < N; i++) {
            if (data[i] != 0)
                data[i] += i;
        }
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
            if ((size_t)data[i] > i)
                std::cout << (char)(data[i] - i);
        }
        std::cout << std::endl;

        std::cout << "Length: " << N << std::endl;
        std::cout << "Rounds: " << rounds() << std::endl;
    }
    
private:
    constexpr size_t rounds() const noexcept
    {
        return ((N + 128 - 1) / 128);
    }
};
