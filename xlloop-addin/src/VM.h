/*******************************************************************************
 * This program and the accompanying materials
 * are made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at 
 * http://www.eclipse.org/legal/cpl-v10.html
 * 
 * Contributors:
 *     Peter Smith
 *******************************************************************************/

#ifndef VM_H
#define VM_H

#include <windows.h>
#include "INI.h"

// VM versions
#define VM_VERSION_MAX ":vm.version.max"
#define VM_VERSION ":vm.version"
#define VM_VERSION_MIN ":vm.version.min"

// VM keys
#define HEAP_SIZE_MAX_PERCENT ":vm.heapsize.max.percent"
#define HEAP_SIZE_MIN_PERCENT ":vm.heapsize.min.percent"
#define HEAP_SIZE_PREFERRED ":vm.heapsize.preferred"

// VM args
#define VM_ARG_HEAPSIZE "-Xmx"

// Encapsulates a VM version number
class Version {
public:
	Version() : Parsed(false) {}
	void Parse(LPSTR version);
	int Compare(Version& other);
	char* GetVersionStr() { return VersionStr; }

private:
	bool Parsed;
	char VersionStr[MAX_PATH];
	int VersionPart[10];
};

// VM utilities
struct VM {
	static char* FindJavaVMLibrary(dictionary *ini);
	static void ExtractSpecificVMArgs(dictionary* ini, TCHAR** args, int& count);
	static char* GetJavaVMLibrary(LPSTR version, LPSTR min, LPSTR max);
	
public:
	static Version* FindVersion(Version* versions, DWORD numVersions, LPSTR version, LPSTR min, LPSTR max);
	static void FindVersions(Version* versions, DWORD* numVersions);
};

#endif // VM_UTILS_H