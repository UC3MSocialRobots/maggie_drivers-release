Name:           ros-hydro-maggie-motor-drivers
Version:        0.0.4
Release:        0%{?dist}
Summary:        ROS maggie_motor_drivers package

Group:          Development/Libraries
License:        LEUC3M v1.0
URL:            http://wiki.ros.org/maggie_motor_drivers
Source0:        %{name}-%{version}.tar.gz

Requires:       ros-hydro-roscpp
Requires:       ros-hydro-sr-communications
BuildRequires:  gmock-devel
BuildRequires:  gtest-devel
BuildRequires:  ros-hydro-catkin
BuildRequires:  ros-hydro-roscpp
BuildRequires:  ros-hydro-sr-communications

%description
motor drivers for Maggie robot

%prep
%setup -q

%build
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree that was dropped by catkin, and source it.  It will
# set things like CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/hydro/setup.sh" ]; then . "/opt/ros/hydro/setup.sh"; fi
mkdir -p obj-%{_target_platform} && cd obj-%{_target_platform}
%cmake .. \
        -UINCLUDE_INSTALL_DIR \
        -ULIB_INSTALL_DIR \
        -USYSCONF_INSTALL_DIR \
        -USHARE_INSTALL_PREFIX \
        -ULIB_SUFFIX \
        -DCMAKE_INSTALL_PREFIX="/opt/ros/hydro" \
        -DCMAKE_PREFIX_PATH="/opt/ros/hydro" \
        -DSETUPTOOLS_DEB_LAYOUT=OFF \
        -DCATKIN_BUILD_BINARY_PACKAGE="1" \

make %{?_smp_mflags}

%install
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree that was dropped by catkin, and source it.  It will
# set things like CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/hydro/setup.sh" ]; then . "/opt/ros/hydro/setup.sh"; fi
cd obj-%{_target_platform}
make %{?_smp_mflags} install DESTDIR=%{buildroot}

%files
/opt/ros/hydro

%changelog
* Thu Sep 10 2015 Raul Perula-Martinez <raul.perula@uc3m.es> - 0.0.4-0
- Autogenerated by Bloom

* Mon Jul 06 2015 Raul Perula-Martinez <raul.perula@uc3m.es> - 0.0.2-0
- Autogenerated by Bloom

* Fri May 01 2015 Raul Perula-Martinez <raul.perula@uc3m.es> - 0.0.1-0
- Autogenerated by Bloom

