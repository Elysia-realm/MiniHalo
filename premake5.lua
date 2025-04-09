workspace "MiniHalo"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    buildoptions
    {
        "/utf-8"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root directory (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "MiniHalo/vendor/GLFW/include"

include "MiniHalo/vendor/GLFW"

project "MiniHalo"
    location "MiniHalo"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    pchheader "hapch.h"
    pchsource "MiniHalo/src/hapch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HALO_PLATFORM_WINDOWS",
            "HALO_BUILD_DLL"
        }
    
    filter "configurations:Debug"
        defines "HA_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "HA_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HA_DIST"
        optimize "On"

project "Editor"
    location "Editor"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "MiniHalo/vendor/spdlog/include",
        "MiniHalo/src"
    }

    links
    {
        "MiniHalo"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HALO_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "HA_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "HA_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HA_DIST"
        optimize "On"