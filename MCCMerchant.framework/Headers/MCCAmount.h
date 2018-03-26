/*
 *    MCCAmount.h
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

@interface MCCAmount : NSObject

///Total to be used for transaction. It may have precision up to 2 decimal places. For example, $12.55 is a valid amount, while $12.456 will not be considered as valid total.
@property(nonatomic, strong, nonnull) NSDecimalNumber *total;

///Currency code. A string representing currency code in which the amount is being charged. The value should be following ISO 4217 standard.
@property(nonatomic, strong, nonnull) NSString *currencyCode;

@end
