/*
 *    MCCMasterpassButton.h
 *    MCCMerchant
 *
 * 	  Copyright © 2015-2017, Mastercard International Incorporated and/or its
 *    affiliates. All rights reserved.
 *
 *    TO THE EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS", WITHOUT
 *    WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *    WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *    NON INFRINGEMENT. TO THE EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 *    MASTERCARD OR ITS AFFILIATES BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *    IN THE SOFTWARE.
 *
 */

#import <UIKit/UIKit.h>

/**
 MCCMasterpassButton implements a "Pay with Masterpass" button on device's touch screen. This class restrict the use of UIButton methods to set title, image and also restrict to add event on UIButton.
 
 Overview:
 
 This class provides API to add itself to specified super view.
 
 */

@interface MCCMasterpassButton : UIButton

/**
 *
 * Adds button to the view.
 *
 * This method will add the object of MCCMasterpassButton on the passed UIView object.
 *
 * @param superView
    UIView object on which button will be added.
 *
 */
- (void)addButtonToview:(UIView* _Nonnull) superView;

@end
