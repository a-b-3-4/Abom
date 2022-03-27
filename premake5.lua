workspace "Abom"
    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Distribution"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Abom"
    location "Abom"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines{
            "AB_PLATFORM_WINDOWS",
            "AB_BUILD_DLL"
        }

        postbuildcommands{
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "AB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "AB_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "Abom/vendor/spdlog/include",
        "Abom/src"
    }

    links{
        "Abom"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines{
            "AB_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "AB_DIST"
        optimize "On"