workspace "EsromeEngine"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "EsromeEngine"
	location "EsromeEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

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
		systemversion "latest"

		defines{
			"EE_PLATFORM_WINDOWS",
			"EE_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "EE_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "EE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "EE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin_int/" .. outputdir .. "/%{prj.name}")
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"EsromeEngine/vendor/spdlog/include",
		"EsromeEngine/src"
	}

	links{
		"EsromeEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"EE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "EE_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "EE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "EE_DIST"
		optimize "On"