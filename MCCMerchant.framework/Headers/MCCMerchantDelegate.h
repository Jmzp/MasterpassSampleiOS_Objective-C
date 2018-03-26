/*
 *    MCCMerchantDelegate
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

#import <Foundation/Foundation.h>
#import "MCCCheckoutResponse.h"

/**
 *  The MCCMerchantDelegate protocol defines the methods which will be implemented by Merchant application. Merchant SDK will trigger the delegate methods to receive payment request data and communicate error status.
 */
@protocol MCCMerchantDelegate <NSObject>
@required

/**
 *  This MCCMerchantDelegate method will be called by MCCMerchant to get the payment request data from merchant application
 *
 *  @param block to provide call back from merchant application to MCCMerchat with MCCCheckoutRequest object
 */
- (void)didGetCheckoutRequest:(nullable BOOL (^) (MCCCheckoutRequest * _Nonnull checkoutRequest))completionBlock;

/**
 *  This MCCMerchantDelegate method will be called by MCCMerchant when transaction gets completed successfully.
 *
 *  @param checkoutResponse to pass checkout response params back to the merchant application.
 */
-(void) didFinishCheckout:(MCCCheckoutResponse * _Nonnull) checkoutResponse;

/**
 *  This MCCMerchantDelegate method will be called by MCCMerchant to provide the error to merchant application in case of transaction failure for any reason.
 */
- (void) didReceiveCheckoutError:(NSError* _Nonnull)error;

@end
