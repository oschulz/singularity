/* 
 * Copyright (c) 2015-2016, Gregory M. Kurtzer. All rights reserved.
 * 
 * “Singularity” Copyright (c) 2016, The Regents of the University of California,
 * through Lawrence Berkeley National Laboratory (subject to receipt of any
 * required approvals from the U.S. Dept. of Energy).  All rights reserved.
 * 
 * This software is licensed under a customized 3-clause BSD license.  Please
 * consult LICENSE file distributed with the sources of this project regarding
 * your rights to use or distribute this software.
 * 
 * NOTICE.  This Software was developed under funding from the U.S. Department of
 * Energy and the U.S. Government consequently retains certain rights. As such,
 * the U.S. Government has been granted for itself and others acting on its
 * behalf a paid-up, nonexclusive, irrevocable, worldwide license in the Software
 * to reproduce, distribute copies to the public, prepare derivative works, and
 * perform publicly and display publicly, and to permit other to do so. 
 * 
*/


#ifndef __SINGULARITY_H_
#define __SINGULARITY_H_


    // ALL NAMESPACES:
    // Unshare all Singularity enabled namespaces automatically
    extern int singularity_ns_unshare(void);
    // Join all namespaces of a particular PID
    extern int singularity_ns_join(pid_t attach_pid);


    // PID NAMESPACE
    // Unshare the PID namespace (if enabled via configuration file)
    extern int singularity_ns_pid_unshare(void);
    // Return 0/1 if the namespace has been unshared
    extern int singularity_ns_pid_enabled(void);

    // FS/FILES NAMESPACE
    // Unshare the various mount/files based namespaces
    extern int singularity_ns_mnt_unshare(void);
    // Return 0/1 if the namespace has been unshared
    extern int singularity_ns_mnt_enabled(void);

    // USER NAMESPACE
    // Unshare the user namespace (if supported by platform itself)
    extern int singularity_ns_user_unshare(void);
    extern int singularity_ns_user_enabled(void);


    // IMAGE
    // Check that a particular file is a valid Singularity image (note this
    // is not an exhaustive check, only checks header)
    extern int singularity_image_check(FILE *image_fp);
    // Determine the image offset (where the actual file system begins on
    // the image)
    extern int singularity_image_offset(FILE *image_fp);
    // Create a new image including the header
    extern int singularity_image_create(char *image, int size);
    // Expand an existing image ...
    extern int singularity_image_expand(char *image, int size);


    // ROOTFS
    // Initialize the rootfs interface and do sanity checks early
    extern int singularity_rootfs_init(char *source, char *mount_point);
    // Mount the rootfs as defined above (source and mount_point are cached)
    extern int singularity_rootfs_mount(void);
    // Do the chroot into the new rootfs
    extern int singularity_rootfs_chroot(void);
    // Return the location of the final rootfs directory/mount point
    extern char *singularity_rootfs_dir(void);


    // LOOP
    // Bind an image to the next available loop device, and return the device
    // name
    extern char *singularity_loop_bind(FILE *image_fp);
    // Free the bound device
    extern int singularity_loop_free(char *loop_dev);


    // ACTION
    // Initialize the action interface and do sanity checks early
    extern int singularity_action_init(void);
    // Do the requested action
    extern int singularity_action_do(int agc, char **argv);


    // MOUNT
    // Mount all file systems as they are configured
    extern int singularity_mount(void);
    // Mount just specific ones (note, they can be overridden by the
    // configuration file)
    extern int singularity_mount_kernelfs(void);
    extern int singularity_mount_binds(void);
    extern int singularity_mount_home(void);
    extern int singularity_mount_tmp(void);


    // FILE
    // Create temporary files incontainers
    extern int singularity_file(void);
    extern int singularity_file_passwd(void);
    extern int singularity_file_group(void);

#endif /* __SINGULARITY_H */
