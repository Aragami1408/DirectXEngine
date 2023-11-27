#include "DXEException.h"

DXEException::DXEException(int line, const char* file) noexcept : line(line), file(file)
{
}

const char* DXEException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* DXEException::GetType() const noexcept
{
	return "DirectX Engine Exception";
}

int DXEException::GetLine() const noexcept
{
	return line;
}

const std::string& DXEException::GetFile() const noexcept
{
	return file;
}

std::string DXEException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File]" << file << std::endl << "[Line]" << line;
	return oss.str();
}
