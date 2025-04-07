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

project "MiniHalo"
    location "MiniHalo"
    kind "SharedLib"
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
        "%{prj.name}/vendor/spdlog/include"
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