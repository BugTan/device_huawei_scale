/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.
   Copyright (c) 2016, The CyanogenMod Project
   Copyright (c) 2019, The LineageOS Project

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <string>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/strings.h>

#include "property_service.h"
#include "vendor_init.h"

using android::base::ReadFileToString;
using android::base::Trim;

using namespace std;

const char *APP_INFO = "/proc/app_info";

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void set_model(const char *model) {
    property_override("ro.build.product", model);
    property_override("ro.product.device", model);
    property_override("ro.product.model", model);
}

void init_target_properties()
{
    ifstream fin;
    string buf;

    fin.open(APP_INFO, ios::in);
    if (!fin) {
        LOG(ERROR) << __func__ << ": Failed to open " << APP_INFO;
        return;
    }

    while (getline(fin, buf))
        if (buf.find("huawei_fac_product_name") != string::npos)
            break;
    fin.close();

    /* SCL-AL00 */
    if (buf.find("SCL-AL00") != string::npos) {
        set_model("SCL-AL00");
        property_set("ro.build.description", "SCL-AL00-user 5.1.1 GRJ90 C00B251 release-keys");
        property_set("ro.build.fingerprint", "Honor/SCL-AL00/hnSCL-Q:5.1.1/HonorSCL-AL00/C00B251:user/release-keys");

    /* SCL-CL00 */
    } else if (buf.find("SCL-CL00") != string::npos) {
        set_model("SCL-CL00");
        property_set("ro.build.description", "SCL-CL00-user 5.1.1 GRJ90 C92B261 release-keys");
        property_set("ro.build.fingerprint", "Honor/SCL-CL00/hnSCL-Q:5.1.1/HonorSCL-CL00/C92B261:user/release-keys");

    /* SCL-L01 */
    } else if (buf.find("SCL-L01") != string::npos) {
        set_model("SCL-L01");
        property_set("ro.build.description", "SCL-L01-user 5.1.1 GRJ90 C432B181 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L01/hwSCL-Q:5.1.1/HuaweiSCL-L01/C432B181:user/release-keys");

    /* SCL-L02 */
    } else if (buf.find("SCL-L02") != string::npos) {
        set_model("SCL-L02");
        property_set("ro.build.description", "SCL-L02-user 5.1.1 GRJ90 C576B130 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L02/hwSCL-Q:5.1.1/HuaweiSCL-L02/C576B130:user/release-keys");

    /* SCL-L03 */
    } else if (buf.find("SCL-L03") != string::npos) {
        set_model("SCL-L03");
        property_set("ro.build.description", "SCL-L03-user 5.1.1 GRJ90 C25B143 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L03/hwSCL-Q:5.1.1/HuaweiSCL-L03/C25B143:user/release-keys");

    /* SCL-L04 */
    } else if (buf.find("SCL-L04") != string::npos) {
        set_model("SCL-L04");
        property_set("ro.build.description", "SCL-L04-user 5.1.1 GRJ90 C654B141 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L04/hwSCL-Q:5.1.1/HuaweiSCL-L04/C654B141:user/release-keys");

    /* SCL-L21 */
    } else if (buf.find("SCL-L21") != string::npos) {
        set_model("SCL-L21");
        property_set("ro.build.description", "SCL-L21-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L21/hwSCL-Q:5.1.1/HuaweiSCL-L21/C432B150:user/release-keys");

    /* SCL-TL00 */
    } else if (buf.find("SCL-TL00") != string::npos) {
        set_model("SCL-TL00");
        property_set("ro.build.description", "SCL-TL00-user 5.1.1 GRJ90 C01B172 release-keys");
        property_set("ro.build.fingerprint", "Honor/SCL-TL00/hnSCL-Q:5.1.1/HonorSCL-TL00/C01B172:user/release-keys");

    /* SCL-TL00H */
    } else if (buf.find("SCL-TL00H") != string::npos) {
        set_model("SCL-TL00H");
        property_set("ro.build.description", "SCL-TL00H-user 5.1.1 GRJ90 C00B172 release-keys");
        property_set("ro.build.fingerprint", "Honor/SCL-TL00H/hnSCL-Q:5.1.1/HonorSCL-TL00H/C00B172:user/release-keys");

    /* SCL-TL10 */
    } else if (buf.find("SCL-TL10") != string::npos) {
        set_model("SCL-TL10");
        property_set("ro.build.description", "SCL-TL10-user 5.1.1 GRJ90 C01B220 release-keys");
        property_set("ro.build.fingerprint", "Honor/SCL-TL10/hnSCL-Q:5.1.1/HonorSCL-TL10/C01B220:user/release-keys");

    /* SCL-TL10H */
    } else if (buf.find("SCL-TL10H") != string::npos) {
        set_model("SCL-TL10H");
        property_set("ro.build.description", "SCL-TL10H-user 5.1.1 GRJ90 C00B220 release-keys");
        property_set("ro.build.fingerprint", "Honor/SCL-TL10H/hnSCL-Q:5.1.1/HonorSCL-TL10H/C00B220:user/release-keys");

    /* SCL-U03 */
    } else if (buf.find("SCL-U03") != string::npos) {
        set_model("SCL-U03");
        property_set("ro.build.description", "SCL-U03-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-U03/hwSCLU-Q:5.1.1/HuaweiSCL-U03/C432B150:user/release-keys");

    /* SCL-U21 */
    } else if (buf.find("SCL-U21") != string::npos) {
        set_model("SCL-U21");
        property_set("ro.build.description", "SCL-U21-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-U21/hwSCLU-Q:5.1.1/HuaweiSCL-U21/C432B150:user/release-keys");

    /* SCL-U23 */
    } else if (buf.find("SCL-U23") != string::npos) {
        set_model("SCL-U23");
        property_set("ro.build.description", "SCL-U23-user 5.1.1 GRJ90 C636B140 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-U23/hwSCLU-Q:5.1.1/HuaweiSCL-U23/C636B140:user/release-keys");

    /* SCL-U31 */
    } else if (buf.find("SCL-U31") != string::npos) {
        set_model("SCL-U31");
        property_set("ro.build.description", "SCL-U31-user 5.1.1 GRJ90 C185B161 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-U31/hwSCLU-Q:5.1.1/HuaweiSCL-U31/C185B161:user/release-keys");

    /* SCC-U21 */
    } else if (buf.find("SCC-U21") != string::npos) {
        set_model("SCC-U21");
        property_set("ro.build.description", "SCC-U21-user 5.1.1 GRJ90 C636B170 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCC-U21/hwSCC-Q:5.1.1/HuaweiSCC-U21/C636B170:user/release-keys");

    } else
        LOG(ERROR) << __func__ << ": unexcepted huawei_fac_product_name!";
}

static void init_alarm_boot_properties()
{
    char const *boot_reason_file = "/proc/sys/kernel/boot_reason";
    char const *power_off_alarm_file = "/persist/alarm/powerOffAlarmSet";
    string boot_reason;
    string power_off_alarm;
    string tmp = property_get("ro.boot.alarmboot");

    if (ReadFileToString(boot_reason_file, &boot_reason)
            && ReadFileToString(power_off_alarm_file, &power_off_alarm)) {
        /*
         * Setup ro.alarm_boot value to true when it is RTC triggered boot up
         * For existing PMIC chips, the following mapping applies
         * for the value of boot_reason:
         *
         * 0 -> unknown
         * 1 -> hard reset
         * 2 -> sudden momentary power loss (SMPL)
         * 3 -> real time clock (RTC)
         * 4 -> DC charger inserted
         * 5 -> USB charger insertd
         * 6 -> PON1 pin toggled (for secondary PMICs)
         * 7 -> CBLPWR_N pin toggled (for external power supply)
         * 8 -> KPDPWR_N pin toggled (power key pressed)
         */
        if ((Trim(boot_reason) == "3" || tmp == "true")
                && Trim(power_off_alarm) == "1")
            property_set("ro.alarm_boot", "true");
        else
            property_set("ro.alarm_boot", "false");
    }
}

void vendor_load_properties()
{
    init_target_properties();
    init_alarm_boot_properties();
}
