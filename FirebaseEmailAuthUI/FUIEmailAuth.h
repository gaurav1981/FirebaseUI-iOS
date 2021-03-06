//
//  Copyright (c) 2018 Email Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import "FUIAuthProvider.h"

@class FUIAuth;
@class FIRActionCodeSettings;
@class FUIEmailEntryViewController;
@class FUIPasswordSignInViewController;
@class FUIPasswordSignUpViewController;
@class FUIPasswordRecoveryViewController;
@class FUIPasswordVerificationViewController;

NS_ASSUME_NONNULL_BEGIN

/** @class FUIEmailAuth
    @brief AuthUI components for Email Sign In.
 */
@interface FUIEmailAuth : NSObject <FUIAuthProvider>

- (instancetype)initAuthAuthUI:(FUIAuth *)authUI
                  signInMethod:(NSString *)signInMethod
               forceSameDevice:(BOOL)forceSameDevice
         allowNewEmailAccounts:(BOOL)allowNewEmailAccounts
             actionCodeSetting:(FIRActionCodeSettings *)actionCodeSettings;


/** @property signInMethod.
    @brief Defines the sign in method for FIREmailAuthProvider.
           This can be one of the following string constants:
             - FIREmailLinkAuthSignInMethod
             - FIREmailPasswordAuthSignInMethod (default).
 */
@property(nonatomic, copy, readonly) NSString *signInMethod;

/** @property forceSameDevice.
    @brief Whether to force same device flow. If not, opening the link on a different device will
           display an error message. Note that this should be true when used with anonymous user
           upgrade flows. The default is false.
 */
@property(nonatomic, assign, readonly) BOOL forceSameDevice;

/** @property actionCodeSettings.
    @brief Defines the FIRActionCodeSettings configuration to use when sending the link. This gives
           the developer the ability to specify how the link can be handled, custom dynamic link,
           additional state in the deep link, etc.
 */
@property(nonatomic, strong, readonly) FIRActionCodeSettings *actionCodeSettings;

/** @property allowNewEmailAccounts
    @brief Whether to allow new user sign, defaults to YES.
 */
@property(nonatomic, assign, readonly) BOOL allowNewEmailAccounts;

/** @fn signInWithPresentingViewController:
    @brief Signs in with email auth provider.
        @see FUIAuthDelegate.authUI:didSignInWithAuthDataResult:URL:error: for method callback.
    @param presentingViewController The view controller used to present the UI.
 */
- (void)signInWithPresentingViewController:(UIViewController *)presentingViewController
__attribute__((deprecated("This is deprecated API and will be removed in a future release."
                          "Please use signInWithPresentingViewController:email:")));

/** @fn signInWithPresentingViewController:email:
    @brief Signs in with email auth provider.
        @see FUIAuthDelegate.authUI:didSignInWithAuthDataResult:URL:error: for method callback.
    @param presentingViewController The view controller used to present the UI.
    @param email The default email address.
 */
- (void)signInWithPresentingViewController:(UIViewController *)presentingViewController
                                     email:(nullable NSString *)email;


@end

NS_ASSUME_NONNULL_END
