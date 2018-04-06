%define name ++dfb
%define version 1.4.2
%define oname ++DFB
%define libname lib%name
%define _unpackaged_files_terminate_build 0

Summary:	Hardware graphics acceleration library
Name:		%name
Version:	%version
Release:	1
License:	LGPL
Group:		System/Libraries
Source0:        %{oname}-%{version}.tar.gz
URL:		http://www.directfb.org/
BuildRequires:	libdirectfb-devel >= 1.4.2
BuildRoot:	%{_tmppath}/%{name}-%{version}

%description
%oname - C++ API for DirectFB

%package -n %libname
Summary:        Shared library part of %oname
Group:		System/Libraries
Requires:	libdirectfb >= 1.4.2

%description -n %libname
%oname - C++ API for DirectFB

%package -n %libname-devel
Group:		Development/C++
Summary:	Header files for compiling %oname applications
Requires:	%{libname} = %{version}-%release
Provides:	lib%name-devel = %version-%release

%description -n %libname-devel
%oname header files needed for building applications based on %oname. 

%prep
%setup  -q -n %oname-%version

%build
%configure

make

%install
rm -rf $RPM_BUILD_ROOT
make DESTDIR=%{buildroot} install

%clean
rm -rf $RPM_BUILD_ROOT

%post -n %libname -p /sbin/ldconfig
%postun -n %libname -p /sbin/ldconfig

%files -n %libname
%defattr(644,root,root,755)
%attr(755,root,root) %{_libdir}/lib*.so.*
%{_libdir}/lib++dfb-*

%files -n %libname-devel
%defattr(644,root,root,755)
%attr(755,root,root) %{_bindir}/*++dfb-config
%{_includedir}/++dfb
%{_libdir}/pkgconfig/*
%{_libdir}/*.la
%{_libdir}/*.so

%changelog
* Mon Jan 08 2007 Mark Adams <mark147m@gmail.com> 0.9.26
- initial package
