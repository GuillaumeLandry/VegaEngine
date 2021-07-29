workspace "Vega"
	architecture "x64"

	configuration {
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg-architecture}"

project "Vega"
	location "Vega"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	targetdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines {
			"VG_PLATFORM_WINDOWS",
			"VG_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "VG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VG_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")	
	targetdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Vega/vendor/spdlog/include",
		"Vega/src"
	}

	links {
		"Vega"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines {
			"VG_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "VG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VG_DIST"
		optimize "On"