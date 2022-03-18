#include <iostream>
#include <compiletime_aes.hpp>

int main()
{
    constexpr aes_key<128> key("0123456789abcdef");
    constexpr compiletime_aes mhm("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Elit ullamcorper dignissim cras tincidunt. Faucibus a pellentesque sit amet porttitor eget dolor. Odio tempor orci dapibus ultrices in iaculis. Platea dictumst quisque sagittis purus sit amet. Urna molestie at elementum eu facilisis sed odio morbi. Nisl tincidunt eget nullam non nisi est sit amet. Parturient montes nascetur ridiculus mus. Tristique senectus et netus et malesuada fames ac turpis. Nisl tincidunt eget nullam non nisi est. Enim facilisis gravida neque convallis a. Non curabitur gravida arcu ac tortor dignissim convallis aenean et. Blandit massa enim nec dui nunc mattis enim ut tellus. Semper auctor neque vitae tempus quam. Commodo sed egestas egestas fringilla phasellus. Tortor aliquam nulla facilisi cras fermentum odio eu. Leo vel orci porta non pulvinar neque. Mauris pellentesque pulvinar pellentesque habitant morbi tristique senectus. Viverra nibh cras pulvinar mattis nunc.", key);
    mhm.print();

    return 0;
}
