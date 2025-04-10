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
IncludeDir["Glad"] = "MiniHalo/vendor/Glad/include"
IncludeDir["ImGui"] = "MiniHalo/vendor/imgui"

include "MiniHalo/vendor/GLFW"
include "MiniHalo/vendor/Glad"
include "MiniHalo/vendor/imgui"

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
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HALO_PLATFORM_WINDOWS",
            "HALO_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }
    
    filter "configurations:Debug"
        defines "HA_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "HA_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "HA_DIST"
        buildoptions "/MD"
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
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "HA_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "HA_DIST"
        buildoptions "/MD"
        optimize "On"